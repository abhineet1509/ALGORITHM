#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int pid, at, bt, pr;
    int ct, tat, wt, rt, bt_remaining, start;
};

void printTable(struct Process p[], int n) {
    float avg_tat=0, avg_wt=0, avg_rt=0;
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt, p[i].pr,
            p[i].ct, p[i].tat, p[i].wt, p[i].rt);
        avg_tat += p[i].tat;
        avg_wt  += p[i].wt;
        avg_rt  += p[i].rt;
    }
    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT  = %.2f", avg_wt/n);
    printf("\nAverage RT  = %.2f\n", avg_rt/n);
}

/* ---------- FCFS ---------- */
void fcfs(struct Process p[], int n) {
    int time=0;
    for(int i=0;i<n;i++) {
        if(time < p[i].at) time = p[i].at;
        p[i].start = time;
        p[i].ct = time + p[i].bt;
        time = p[i].ct;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;
        p[i].rt  = p[i].start - p[i].at;
    }
    printTable(p,n);
}

/* ---------- SJF Non-Preemptive ---------- */
void sjf(struct Process p[], int n) {
    int completed=0, time=0;
    int isCompleted[n];
    for(int i=0;i<n;i++) isCompleted[i]=0;

    while(completed<n) {
        int idx=-1, minBT=INT_MAX;
        for(int i=0;i<n;i++) {
            if(p[i].at<=time && !isCompleted[i]) {
                if(p[i].bt < minBT) {
                    minBT=p[i].bt; idx=i;
                }
            }
        }
        if(idx==-1) { time++; continue; }
        p[idx].start = time;
        p[idx].ct = time + p[idx].bt;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt  = p[idx].tat - p[idx].bt;
        p[idx].rt  = p[idx].start - p[idx].at;

        time = p[idx].ct;
        isCompleted[idx]=1; completed++;
    }
    printTable(p,n);
}

/* ---------- SRTF (Preemptive SJF) ---------- */
void srtf(struct Process p[], int n) {
    int completed=0, time=0;
    for(int i=0;i<n;i++) { p[i].bt_remaining=p[i].bt; p[i].start=-1; }

    while(completed<n) {
        int idx=-1, minBT=INT_MAX;
        for(int i=0;i<n;i++) {
            if(p[i].at<=time && p[i].bt_remaining>0) {
                if(p[i].bt_remaining < minBT) {
                    minBT=p[i].bt_remaining; idx=i;
                }
            }
        }
        if(idx==-1) { time++; continue; }

        if(p[idx].start==-1) p[idx].start=time;

        p[idx].bt_remaining--;
        time++;

        if(p[idx].bt_remaining==0) {
            p[idx].ct=time;
            p[idx].tat=p[idx].ct - p[idx].at;
            p[idx].wt=p[idx].tat - p[idx].bt;
            p[idx].rt=p[idx].start - p[idx].at;
            completed++;
        }
    }
    printTable(p,n);
}

/* ---------- Round Robin ---------- */
void rr(struct Process p[], int n, int tq) {
    int time=0, completed=0;
    for(int i=0;i<n;i++) { p[i].bt_remaining=p[i].bt; p[i].start=-1; }

    while(completed<n) {
        int done=1;
        for(int i=0;i<n;i++) {
            if(p[i].bt_remaining>0 && p[i].at<=time) {
                done=0;
                if(p[i].start==-1) p[i].start=time;
                if(p[i].bt_remaining>tq) {
                    p[i].bt_remaining -= tq;
                    time += tq;
                } else {
                    time += p[i].bt_remaining;
                    p[i].bt_remaining=0;
                    p[i].ct=time;
                    p[i].tat=p[i].ct - p[i].at;
                    p[i].wt=p[i].tat - p[i].bt;
                    p[i].rt=p[i].start - p[i].at;
                    completed++;
                }
            }
        }
        if(done) time++;
    }
    printTable(p,n);
}

/* ---------- Non-Preemptive Priority ---------- */
void priority_np(struct Process p[], int n) {
    int completed=0, time=0;
    int isCompleted[n];
    for(int i=0;i<n;i++) isCompleted[i]=0;

    while(completed<n) {
        int idx=-1, maxPr=-1;
        for(int i=0;i<n;i++) {
            if(p[i].at<=time && !isCompleted[i]) {
                if(p[i].pr > maxPr) { maxPr=p[i].pr; idx=i; }
            }
        }
        if(idx==-1) { time++; continue; }
        p[idx].start=time;
        p[idx].ct=time+p[idx].bt;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        p[idx].rt=p[idx].start-p[idx].at;

        time=p[idx].ct;
        isCompleted[idx]=1; completed++;
    }
    printTable(p,n);
}

/* ---------- Preemptive Priority ---------- */
void priority_p(struct Process p[], int n) {
    int completed=0, time=0;
    for(int i=0;i<n;i++){ p[i].bt_remaining=p[i].bt; p[i].start=-1; }

    while(completed<n) {
        int idx=-1, maxPr=-1;
        for(int i=0;i<n;i++) {
            if(p[i].at<=time && p[i].bt_remaining>0) {
                if(p[i].pr > maxPr) { maxPr=p[i].pr; idx=i; }
            }
        }
        if(idx==-1) { time++; continue; }

        if(p[idx].start==-1) p[idx].start=time;

        p[idx].bt_remaining--; time++;
        if(p[idx].bt_remaining==0) {
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            p[idx].rt=p[idx].start-p[idx].at;
            completed++;
        }
    }
    printTable(p,n);
}

/* ---------- Main ---------- */
int main() {
    int n, choice, tq;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];
    for(int i=0;i<n;i++) {
        printf("Enter AT, BT, Priority for P%d: ", i+1);
        p[i].pid=i+1;
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
    }

    printf("\nChoose Algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. SRTF\n4. RR\n5. Priority (NP)\n6. Priority (P)\nChoice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1: fcfs(p,n); break;
        case 2: sjf(p,n); break;
        case 3: srtf(p,n); break;
        case 4: printf("Enter Time Quantum: "); scanf("%d",&tq); rr(p,n,tq); break;
        case 5: priority_np(p,n); break;
        case 6: priority_p(p,n); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
