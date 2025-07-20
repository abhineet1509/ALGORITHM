import math

def is_possible(px, py, qx, qy, a):
    dx = qx - px
    dy = qy - py
    dist = math.sqrt(dx*dx + dy*dy)
    total = sum(a)
    
    if dist > total:
        return False
    
    # Check if we can cancel out the remaining movement (even number)
    return (total - dist) % 2 <= 1e-6  # due to floating point issues

t = int(input())
for _ in range(t):
    n = int(input())
    px, py, qx, qy = map(int, input().split())
    a = list(map(int, input().split()))
    
    print("Yes" if is_possible(px, py, qx, qy, a) else "No")
