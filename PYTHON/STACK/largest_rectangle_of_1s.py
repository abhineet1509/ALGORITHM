def max_rectangle(mat):
    def hist(h):
        stack=[]
        maxA=0
        h.append(0)
        for i in range(len(h)):
            while stack and h[stack[-1]]>h[i]:
                height=h[stack.pop()]
                width=i if not stack else i-stack[-1]-1
                maxA=max(maxA,height*width)
            stack.append(i)
        return maxA

    res=[0]*len(mat[0])
    ans=0
    for row in mat:
        for i in range(len(row)):
            res[i]=res[i]+1 if row[i]==1 else 0
        ans=max(ans,hist(res[:]))
    return ans

r,c = map(int,input().split())
mat = [list(map(int,input().split())) for _ in range(r)]
print(max_rectangle(mat))
