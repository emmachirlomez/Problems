#include<string>
#include<vector>
#include<iostream>
#include<assert.h>
using namespace std;


/**
 * Vrem sa facem un editor de texte. Vrem sa reprezentam starea editorului si sa acceptam taste care pot
 * sa fie un caracter, backspace, sau o sageata.
 */
class Editor {
    vector<string> content;
    size_t cursor_x;
    size_t cursor_y;

public:

    Editor() {
        content.push_back("");
        cursor_x = 0, cursor_y = 0;
    }

    void AddCharacter(char c) {
        // first case: c is a letter or a symbol
        if (c != '\n') {
            // insert c at position (cursor_x, cursor_y)
            content[cursor_x].insert(content[cursor_x].begin() + cursor_y, c);
            // update cursor_y
            cursor_y++;
        }
        else {
            // second case: c is newline
            // abc|defg
            // =>
            // abc
            // |defg
            
            // save the characters to the right of the cursor
            string right_of_cursor = content[cursor_x].substr(cursor_y);

            // delete substring at the right of the cursor
            content[cursor_x].resize(cursor_y);

            content.insert(content.begin() + cursor_x + 1, right_of_cursor);

            cursor_x++, cursor_y = 0;
        }
    }

    void Backspace() {
        /**
         * Case 1:
         * abc|d
         * =>
         * ab|d
         * 
         * Case 2:
         * abc
         * |efg
         * =>
         * abc|efg
         * 
         * Case 3:
         * |abcd
         * =>
         * |abcd
         */

        if (cursor_x == 0 && cursor_y == 0)
            return;
        if (cursor_y == 0) {
            content[cursor_x - 1].append(content[cursor_x]);
            content.erase(content.begin() + cursor_x);
            cursor_x--;
            cursor_y = content[cursor_x].size();
        }
        else {
            content[cursor_x].erase(content[cursor_x].begin() + cursor_y - 1);
            cursor_y--;
        }
    }

    void UpArrow() { 
        /**
         * Case 1:
         * aaa
         * bbggb|
         * => 
         * aaa|
         * bbggb
         * 
         * Case 2:
         * aaa|ff =>
         * |aaaff
         */
        if (cursor_x == 0)
            cursor_y = 0;
        else {
            cursor_x--;
            cursor_y = min(content[cursor_x].size(), cursor_y);
        }
    }

    void LeftArrow() {
        if (cursor_y == 0 && cursor_x == 0)
            return;
        if (cursor_y == 0) {
            cursor_x--;
            cursor_y = content[cursor_x].size();
        }
        else
            cursor_y--;
    }

    pair<size_t, size_t> GetCursor() const {
        return {cursor_x, cursor_y};
    }

    string GetContent() const {
        string answer;
        for (auto line : content) {
            answer.append(line);
            answer.push_back('\n');
        }
        answer.pop_back();

        return answer;
    }

};


bool TestArrowUp1() {
    // abcd
    // efghij|k
    // =>
    // abcd|
    // efghijk
    Editor e;
    for (char c: static_cast<string>("abcd\nefghijk"))
        e.AddCharacter(c);
    assert(e.GetCursor() == make_pair(1, 7));
    e.LeftArrow();
    e.UpArrow();
    assert(e.GetCursor() == make_pair(0, 4));
    return true;
}

bool TestArrowUp2() {
    // abcdefghijklm
    // efghij|k
    // =>
    // abcdefg|hijklm
    // efghijk
    Editor e;
    for (char c: static_cast<string>("abcdefghijklm\nefghijk"))
        e.AddCharacter(c);
    assert(e.GetCursor() == make_pair(1, 7));
    e.LeftArrow();
    e.UpArrow();
    auto [x, y] = e.GetCursor();
    cout << x << " " << y << '\n';
    assert(e.GetCursor() == make_pair(0, 6));
    return true;
}


int main() {
    TestArrowUp1();
    TestArrowUp2();
}