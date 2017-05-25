# coding: UTF-8
def qs (l):
    if len(l) <= 1:
        return l
    
    # 分割
    # print l
    th = l[0]
    list = l[1:]
    
    # 統合 (ansを介さずにやろうとするとNoneと配列の加算はダメ云々言われる)
    left = qs([x for x in list if x <= th])
    right = qs([x for x in list if x > th])
    ans = []
    ans += left
    ans += [th]
    ans += right
    return ans

print qs([28,78,523,5,35,8,612,49,8,767,324,78,42,36,872,376,32,8762,139,42,0,7])
