#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <string>
#include <iostream>


class Piece {
    public:
	    static std::string currentPosition();
};

class Pawn : public Piece {
    public:
	    bool isBlack(); 
	    static std::string movePawn(int); 

};

class Rook : public Piece  {
    public:
        bool isBlack();
	    static std::string moveRook(int);
};

class Bishop : public Piece{
    public:
        bool isBlack();
	    static std::string moveBishop(int);
};

class Knight : public Piece{
    public:
        bool isBlack();
	    static std::string moveKnight(int);
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
