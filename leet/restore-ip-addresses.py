class Solution:
    def validPortion(self, s: str) -> bool:
        if len(s) == 0:
            return False
        
        if len(s) >= 2 and s[0] == '0':
            return False

        return 0 <= int(s) <= 255

    def restoreIpAddresses(self, s: str) -> list[str]:
        res = []

        for i in range(1, 4):
            for j in range(1, 4):
                for k in range(1, 4):
                    s1 = s[0 : i]
                    s2 = s[i : i+j]
                    s3 = s[i+j : i+j+k]
                    s4 = s[i+j+k : ]

                    if (self.validPortion(s1) and
                        self.validPortion(s2) and
                        self.validPortion(s3) and
                        self.validPortion(s4)):
                        res.append('.'.join([s1, s2, s3, s4]))
        
        return res
