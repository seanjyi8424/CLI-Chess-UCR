#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <string>
#include <iostream>
#include <array>

class Piece {
    protected:
    int cpX;
    int cpY;
    std::string type;
    std::string color;
    public:
    Piece() { }
    virtual char getPiece() = 0;
    virtual bool viable(int x, int y) = 0;
    virtual std::string getColor() = 0;
    bool isValid(Piece* dest, int x, int y) { //Strategy function that calls the Concrete Strategy in Pawn, Bishop...//
        if (dest == nullptr) { // Need to call this in first because nullptr's cant use getColor() function
            if (this->viable(y, x) == true) { //pass in 2 ints to see if its valid also this is the concrete strategy call//
                return true;
            }
            return false;
        }
        else if (this->getColor() != dest->getColor()) {
            if (this->viable(y, x) == true) { //pass in 2 ints to see if its valid//
                return true;
            }
            return false;
        }
        else if (this->getColor() == dest->getColor()) {
            std::cout << "FRIENDLY FIRE/DIDN'T MOVE" << std::endl;
            return false;
        }
        return false;
    }
	   // static std::string currentPosition(); //replaced with member variables cpX & cpY
};

class Pawn : public Piece {
    private:
	int cpX = -1;
	int cpY = -1;
	bool move2 = true; //pawns can move two spaces on their first turn//
	std::string color;
    public:
    Pawn(std::string c, int x, int y) {
        cpX = y; //current position of x is set to y because arrays are flipped in design
        cpY = x; //same as above//
        color = c;
    }
    std::string getColor() {
        return color;
    }
    char getPiece() {
        if (color == "black") {
            return 'p';
        }
        else {
            return 'P';
        }
   }
    bool viable(int x , int y) { //CONCRETE STRATEGY FOR PAWN//
        if (cpX == x && cpY == y) { // Base case if piece doesn't move
            std::cout << "Didn't move..." << std::endl;
            return false;
        }
        if (cpX == x && abs(cpY - y) <= 2) { //checks for vertical movement
            if (move2 == true && abs(cpY - y) == 2) { //if moving 2 spaces
                move2 = false;
                cpX = x;
                cpY = y;
                return true;
            }
            else if (abs(cpY - y) < 2) { //if moving 1 space
                cpX = x;
                cpY = y;
                move2 = false; 
                return true;
            }
            return false;
        }
        else if (abs(cpX - x) == 1) { //Checks for diagonal movement aka kill//
            if (getPiece() == 'p') {
                if (cpY - y == -1) { //Black moves down so should be negative
                    std::cout << "KILLED WHITE" << std::endl;
                    move2 = false;
                    cpX = x;
                    cpY = y;
                    return true;
                }
            }
            else if (getPiece() == 'P') {
                if (cpY - y == 1) { //White moves up so should be positive
                    std::cout << "KILLED BLACK" << std::endl;
                    move2 = false;
                    cpX = x;
                    cpY = y;
                    return true;
                }
            }
            return false;
        }
        std::cout << "CAN'T MOVE THERE" << std::endl;
        return false;
    }
};

class Rook : public Piece  {
	public:
        bool isBlack();
	    static std::string moveRook(int);
};

class Bishop : public Piece{
    private:
    int cpX = -1;
    int cpY = -1;
    std::string color;

    public:
    Bishop(std::string c, int x, int y) {
        cpX = y;
        cpY = x;
        color = c;
    }
    std::string getColor() {
        return color;
    }
    char getPiece() {
        if (color == "black") {
            return 'b';
        }
        else {
            return 'B';
        }
    }
    bool viable(int x , int y) {
        if (cpX == x && cpY == y) { // Base case if piece doesn't move
            std::cout << "Didn't move..." << std::endl;
            return false;
        }
        else if (abs(cpX - x) == abs(cpY - y)) { // Checks for diagonal movement;
            cpX = x;
            cpY = y;
            return true;
        }
        return false;
    }
};

class Knight : public Piece{
    private:
    int cpX = -1;
    int cpY = -1;
    std::string color;

    public:
    Knight(std::string c, int x, int y) {
        cpX = y;
        cpY = x;
        color = c;
    }
    std::string getColor() {
        return color;
    }
    char getPiece() {
        if (color == "black") {
            return 'n';
        }
        else {
            return 'N';
        }
    }
    bool viable(int x , int y) {
        if (cpX == x && cpY == y) { // Base case if piece doesn't move
            std::cout << "Didn't move..." << std::endl;
            return false;
        }
        if (abs(cpX - x) * abs(cpY - y) == 2) { // Knight movement
            cpX = x;
            cpY = y;
            return true;
        }
        return true;
    }
};

class Queen : public Piece{
    public:
        bool isBlack();
	    static std::string moveQueen(int);
};

class King : public Piece{
    public:
        bool isBlack();
	    static std::string moveKing(int);
};
