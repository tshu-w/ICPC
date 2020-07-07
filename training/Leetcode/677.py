class TrieNode(object):
    __slots__ = "children", "val"

    def __init__(self):
        self.children = {}
        self.val = 0


class MapSum:
    def __init__(self):
        self.map = {}
        self.root = TrieNode()

    def insert(self, key: str, val: int) -> None:
        delta = val - self.map.get(key, 0)
        self.map[key] = val
        cur = self.root
        for char in key:
            cur = cur.children.setdefault(char, TrieNode())
            cur.val += delta

    def sum(self, prefix: str) -> int:
        cur = self.root
        for char in prefix:
            if char not in cur.children:
                return 0
            cur = cur.children[char]

        return cur.val


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
