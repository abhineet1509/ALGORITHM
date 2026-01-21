class Solution:
    def exist(self, board, word):
        rows, cols = len(board), len(board[0])

        def backtrack(r, c, idx):
            if idx == len(word):
                return True
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] != word[idx]:
                return False
            
            temp = board[r][c]
            board[r][c] = '#'  # mark as visited
            # explore 4 directions
            found = (backtrack(r+1, c, idx+1) or
                     backtrack(r-1, c, idx+1) or
                     backtrack(r, c+1, idx+1) or
                     backtrack(r, c-1, idx+1))
            board[r][c] = temp  # unmark
            return found

        for i in range(rows):
            for j in range(cols):
                if backtrack(i, j, 0):
                    return True
        return False

# Example
board = [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
]
sol = Solution()
print(sol.exist(board, "ABCCED"))  # True
print(sol.exist(board, "SEE"))     # True
print(sol.exist(board, "ABCB"))    # False


class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None  # store word at the end

class Solution:
    def findWords(self, board, words):
        root = TrieNode()
        # Build Trie
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.word = word  # mark end of word

        rows, cols = len(board), len(board[0])
        result = []

        def dfs(r, c, node):
            char = board[r][c]
            if char not in node.children:
                return
            node = node.children[char]
            if node.word:
                result.append(node.word)
                node.word = None  # avoid duplicates

            board[r][c] = '#'  # mark visited
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                    dfs(nr, nc, node)
            board[r][c] = char  # unmark

        for i in range(rows):
            for j in range(cols):
                dfs(i, j, root)

        return result

# Example
board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
sol = Solution()
print(sol.findWords(board, words))  # Output: ['oath', 'eat']
