from collections import defaultdict
class Solution:

    def find(self, uf, x):
        while uf[x] != x:
            x = uf[x]
        return uf[x]

    def union(self, uf, x, y):
        if x not in uf:
            uf[x] = x
        if y not in uf:
            uf[y] = y
        uf[self.find(uf, x)] = self.find(uf,y)

    def accountsMerge(self, accounts):
        m = defaultdict(str)
        # m root->name
        uf = dict()
        for acclist in accounts:
            if acclist[0] not in m.values():
                m[acclist[1]] = acclist[0]
                for x in acclist[1:]:
                    uf[x] = acclist[1] # 所有的在当前list里面的邮箱的根结点设为acclist[1]
            else:
                for x in acclist[1:]:
                    self.union(uf, acclist[1], x)
                m[self.find(uf, acclist[1])] = acclist[0]
        res = defaultdict(list)
        for k,v in uf.items():
            res[self.find(uf,v)].append(k)
        
        fm = []
        for k,v in m.items():
            fm.append(self.find(uf,k))
        fm = list(set(fm))
    
        fres = []
        # print(fm)
        # print(m)
        # print(uf)
        for f in fm:
            tmp = [m[f]]
            tmp.extend(sorted(res[f]))
            fres.append(tmp)
        return fres

inp = [["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]
s1 = Solution() 
fres = s1.accountsMerge(inp)
print(fres)


