
class Solution {
    class TrieNode {
        boolean isEnd;
        TrieNode[] children;
        
        TrieNode() {
            isEnd = false;
            children = new TrieNode[26];
        }
    }

    class Trie {
        TrieNode root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEnd = true;
        }
        
        String getShortestRoot(String word) {
            TrieNode node = root;
            StringBuilder prefix = new StringBuilder();
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    break;
                }
                node = node.children[index];
                prefix.append(c);
                if (node.isEnd) {
                    return prefix.toString();
                }
            }
            return word;
        }
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String root : dictionary) {
            trie.insert(root);
        }

        String[] words = sentence.split(" ");
        StringBuilder ans = new StringBuilder();

        for (String word : words) {
            if (ans.length() > 0) {
                ans.append(" ");
            }
            ans.append(trie.getShortestRoot(word));
        }

        return ans.toString();
    }
}
