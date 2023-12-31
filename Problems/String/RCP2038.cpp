// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

/*Problem : There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.*/
#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<map>
// #include<unordered_map>
using namespace std;

/*Solution 1 : brute force-

player=alice
while(gettingTheColorPieces) {
    if(player=alice) {
        if(searchPiecesOf(A in colors)) player=bob
        else return false(bob wins)
    }
    if(player=bob) {
        if(searchPieces(B in colors)) player=alice
        else return true(alice wins)
    }
}
searchPieces(key) {
    for(each i 1 to colors.size()-2) {
        if(pieces exists) {
            remove that element from colors
            return 1
        }
    }
    return 0
}
*/
int search(string& colors, char key) {
    if(colors.size()<3) return 0;
    for(int i=1; i<=colors.size()-2; i++) {
        if(colors[i] == key && colors[i - 1] == key && colors[i + 1] == key) {
            while(i<colors.size()-1) {
                i++;
                colors[i]=colors[i+1];
            }   
            colors[i]='\n';
            return 1;
        }
    }
    return 0;
}

class Solution {
public:
    bool winnerOfGame(string colors) {
        int player=1, gettingElems=1;
        while(gettingElems) {
            if(player==1) {
                if(search(colors, 'A')) player=0;
                else return false;
            }
            if(player==0) {
                if(search(colors, 'B')) player=1;
                else return true;
            }
        }
        assert(false);
    }
};

/*solution 2:
count no. of moves alice and bob can move
if(aliceMove<=bob or aliceMove==0) bob wins
else alice wins
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0, bob=0;
        if(colors.size()<3) return false;
        for(int i=1; i<colors.size()-1; i++) {
            if(colors[i]=='A' && colors[i]==colors[i-1] && colors[i]==colors[i+1]) alice++;
            if(colors[i]=='B' && colors[i]==colors[i-1] && colors[i]==colors[i+1]) bob++;
        }
        if(alice<=bob || alice==0) return false;
        return true;
    }
};