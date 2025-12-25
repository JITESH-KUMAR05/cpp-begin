

















#include <bits/stdc++.h>
using namespace std;

static string block_key(const vector<string>& rows, int idx) {
    string k;
    for (int r = 0; r < 3; ++r) k += rows[r].substr(idx*3, 3);
    return k;
}
static string block_binary(const vector<string>& rows, int idx) {
    string b;
    for (int r = 0; r < 3; ++r) {
        string s = rows[r].substr(idx*3, 3);
        for (char c : s) b.push_back(c == ' ' ? '0' : '1');
    }
    return b;
}
static string pad_left(const string &s, int L) {
    if ((int)s.size() >= L) return s;
    return string(L - s.size(), '0') + s;
}
static string op_not(const string &a) {
    string r; r.reserve(a.size());
    for (char c : a) r.push_back(c == '0' ? '1' : '0');
    return r;
}
static string op_bin(const string &a_, const string &op, const string &b_) {
    int L = max((int)a_.size(), (int)b_.size());
    string a = pad_left(a_, L), b = pad_left(b_, L);
    string r; r.resize(L);
    if (op == "||") {
        for (int i = 0; i < L; ++i) r[i] = (a[i]=='1' || b[i]=='1') ? '1' : '0';
    } else { // &&
        for (int i = 0; i < L; ++i) r[i] = (a[i]=='1' && b[i]=='1') ? '1' : '0';
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> digit_rows(3);
    for (int i = 0; i < 3; ++i) {
        if(!std::getline(cin, digit_rows[i])) return 0;
        if(digit_rows[i].size() == 0 && !cin.eof()) { --i; continue; }
    }

    int digit_count = (int)digit_rows[0].size() / 3;
    int D = max(10, digit_count);
    unordered_map<string,string> key_to_sym;
    unordered_map<string,string> digit_to_bin;
    unordered_map<string,string> bin_to_digit;
    for (int i = 0; i < D && i < digit_count; ++i) {
        string k = block_key(digit_rows, i);
        string b = block_binary(digit_rows, i);
        string sym = to_string(i);
        key_to_sym[k] = sym;
        digit_to_bin[sym] = b;
        bin_to_digit[b] = sym;
    }

    vector<string> op_rows(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, op_rows[i]);
        if(op_rows[i].size() == 0 && !cin.eof()) { --i; continue; }
    }
    vector<string> op_syms = {"||","&&","!","(",")"};
    int op_count = (int)op_rows[0].size() / 3;
    for (int i = 0; i < (int)op_syms.size() && i < op_count; ++i) {
        string k = block_key(op_rows, i);
        key_to_sym[k] = op_syms[i];
    }

    vector<string> expr_rows(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, expr_rows[i]);
        if(expr_rows[i].size() == 0 && !cin.eof()) { --i; continue; }
    }
    int expr_count = (int)expr_rows[0].size() / 3;
    vector<string> tokens;
    tokens.reserve(expr_count);
    for (int i = 0; i < expr_count; ++i) {
        string k = block_key(expr_rows, i);
        auto it = key_to_sym.find(k);
        if (it == key_to_sym.end()) {
            string kb;
            for (int r=0;r<3;++r) {
                string s = expr_rows[r].substr(i*3,3);
                for (char c: s) kb.push_back(c==' ' ? '0' : '1');
            }
            bool found=false;
            for (auto &p : key_to_sym) if (p.first == k) { tokens.push_back(p.second); found=true; break; }
            if(!found) {
                // unknown
            }
        } else tokens.push_back(it->second);
    }

    vector<string> grouped;
    string cur_bin;
    for (auto &t : tokens) {
        if (!t.empty() && isdigit((unsigned char)t[0])) {
            cur_bin += digit_to_bin[t];
        } else {
            if (!cur_bin.empty()) { grouped.push_back(cur_bin); cur_bin.clear(); }
            grouped.push_back(t);
        }
    }
    if (!cur_bin.empty()) grouped.push_back(cur_bin);

    unordered_map<string,int> prec;
    prec["!"] = 3;
    prec["||"] = 2;
    prec["&&"] = 1;
    prec["("] = 0;

    stack<string> opers;
    stack<string> vals;
    auto apply_one = [&](){
        if (opers.empty()) return;
        string o = opers.top(); opers.pop();
        if (o == "!") {
            if (vals.empty()) return;
            string v = vals.top(); vals.pop();
            vals.push(op_not(v));
        } else {
            if (vals.size() < 2) return;
            string b = vals.top(); vals.pop();
            string a = vals.top(); vals.pop();
            vals.push(op_bin(a, o, b));
        }
    };

    for (auto &tk : grouped) {
        if (!tk.empty() && (tk.find('0') != string::npos || tk.find('1') != string::npos)) {
            vals.push(tk);
        } else if (tk == "(") {
            opers.push(tk);
        } else if (tk == ")") {
            while (!opers.empty() && opers.top() != "(") apply_one();
            if (!opers.empty() && opers.top() == "(") opers.pop();
        } else { 
            string cur = tk;
            while (!opers.empty() && prec[opers.top()] >= prec[cur]) {
                if (opers.top() == "(") break;
                apply_one();
            }
            opers.push(cur);
        }
    }
    while (!opers.empty()) apply_one();
    if (vals.empty()) { cout << "0\n"; return 0; }
    string result = vals.top();

    
    string out;
    for (size_t i = 0; i < result.size(); i += 9) {
        string chunk = result.substr(i, 9);
        auto it = bin_to_digit.find(chunk);
        if (it != bin_to_digit.end()) out += it->second;
        else {
            
            long long val = 0;
            for (char c : chunk) { val = (val<<1) + (c=='1'); }
            out += to_string(val);
        }
    }
    
    cout << out << '\n';
    return 0;
}