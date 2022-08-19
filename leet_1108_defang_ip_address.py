class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        res = ''
        for c in address:
            if c == '.':
                res += '[.]'
            else:
                res += c
        return res
