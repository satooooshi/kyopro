// oomoji,komoji 52^3 patterns
int N;
string S[201010];
map<string, vector<string>> E, RE; // edge, reverse edge
map<string, int> ans, cnt;
enum { LOOP = 0, LOSE, WIN };
string statements[3] = { "Draw", "Takahashi", "Aoki" };
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> S[i];

    set<string> nodes;
    rep(i, 0, N) {
        string pre = S[i].substr(0, 3);
        string post = S[i].substr(S[i].length() - 3);
        E[pre].push_back(post);
        RE[post].push_back(pre);
        cnt[pre]++; // #words starting from first three letters are pre, pre kara senni kanou na sennisaki no kosuu
        nodes.insert(pre);
        nodes.insert(post);
    }

    queue<string> que;
    fore(cu, nodes) if (cnt[cu] == 0) { 
        ans[cu] = LOSE; // whether or not can answer the word from the first three letters are cu
        que.push(cu); // backtrack from LOSE states
    }
    
    while (!que.empty()) {
        auto cu = que.front(); que.pop();

        fore(pa, RE[cu]) if (ans[pa] == LOOP) { // fore(pa, RE[cu]) backtrack here from cu to pa, ans[pa]==LOOP means not visited yet
            cnt[pa]--; // move the chess onto pa node
            if (ans[cu] == LOSE) {
                ans[pa] = WIN;
                que.push(pa);
            }
            else if (cnt[pa] == 0) { // 　senninoto ga WIN, node pa kara no sennisaki cnt[pa] == 0 yori, ans[pa] = LOSE(means pa kara senni hukanou)
                ans[pa] = LOSE;
                que.push(pa);
            }
        }
    }

    rep(i, 0, N) {
        string post = S[i].substr(S[i].length() - 3);
        printf("%s\n", statements[ans[post]].c_str());
    }
}