/*    127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string> > m;
        for(int i = 0; i < wordList.size(); i++)
        {
            for(int j = i + 1; j < wordList.size(); j++)
            {
                if(diff(wordList[i], wordList[j]) == 1)
                {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i = 0; i < wordList.size(); i++)
        {
            if(diff(beginWord, wordList[i]) == 1)
            {
                m[wordList[i]].push_back(beginWord);
                m[beginWord].push_back(wordList[i]);
            }
        }
        return bfs(m, endWord, beginWord);
    }
    
    int bfs(unordered_map<string, vector<string> > &m, string &endWord, string &beginWord)
    {
        queue<pair<string, int> > q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty())
        {
            pair<string, int> it = q.front();
            string st = it.first;
            int lev = it.second;
            q.pop();
            for(auto s : m[st])
            {
                if(visited.find(s) == visited.end())
                {
                    q.push({s, lev + 1});
                    visited.insert(s);
                    if(s == endWord) return lev + 1;
                }
            }
        }
        return 0;
    }
    int diff(string &a, string &b)
    {
        int count = 0;
        if(a.length() != b.length()) return -1;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
                count++;
        }
        return count;
    }
