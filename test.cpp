#include "Board.h"
#include "Board.cpp"
#include "gtest/gtest.h"

TEST(PawnTest, black) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[1][i]->getPiece(), 'p');
    }
    test->emptyBoard();
    delete test;
}
TEST(PawnTest, white) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[6][i]->getPiece(), 'P');
    }
    test->emptyBoard();
    delete test;
}
TEST(RoyalTest, black) {
    Board* test = new Board("test");
    std::string temp = "";
    for (int i = 0; i < 8; ++i) {
        temp += test->board[0][i]->getPiece();
    }
    ASSERT_EQ(temp, "rnbqkbnr");
    test->emptyBoard();
    delete test;
}
TEST(RoyalTest, white) {
    Board* test = new Board("test");
    std::string temp = "";
    for (int i = 0; i < 8; ++i) {
        temp += test->board[7][i]->getPiece();
    }
    ASSERT_EQ(temp, "RNBQKBNR");
    test->emptyBoard();
    delete test;
}
TEST(ColorTestPawn, black) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[1][i]->getColor(), "black");
    }
    test->emptyBoard();
    delete test;
}
TEST(ColorTestPawn, white) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[6][i]->getColor(), "white");
    }
    test->emptyBoard();
    delete test;
}
TEST(ColorTestRoyal, black) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[0][i]->getColor(), "black");
    }
    test->emptyBoard();
    delete test;
}
TEST(ColorTestRoyal, white) {
    Board* test = new Board("test");
    for (int i = 0; i < 8; ++i) {
        ASSERT_EQ(test->board[7][i]->getColor(), "white");
    }
    test->emptyBoard();
    delete test;
}
TEST(EmptySquare, null) {
    Board* test = new Board("test");
    for (int i = 2; i < 6; ++i) {
	for (int j = 0; j < 8; ++j) {
		ASSERT_EQ(test->board[i][j], nullptr);
	}
    }
    test->emptyBoard();
    delete test;
}
TEST(GameOver, false) {
    Board* test = new Board("test");
    ASSERT_EQ(test->gameEnd(), false);
    test->emptyBoard();
    delete test;
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
