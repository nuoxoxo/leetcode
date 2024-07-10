class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        N = len(s)
        def make (i: int, fields: List[str]) -> None:
            nonlocal res
            if len(fields) == 4:
                if i == N:
                    res.append('.'.join(fields))
                return
            for pos in [1,2,3]: # 1.~ or 35.~ or 225.~
                if i + pos > N:
                    break
                field = s[ i : i + pos ]
                if field[0] == '0' and len(field) > 1:
                    # leading zero(s)
                    break
                if not -1 < int(field) < 256:
                    # valid 8-bit field
                    break
                fields.append( field )
                make (i + pos, fields)
                fields.pop()
        make(0, [])
        return res
