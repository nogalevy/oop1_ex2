#include "Board.h"
#include "controller.h"

//===============================================

Board::Board() :m_BoardSize(0) {}

Board::Board(std::vector <std::string> b, int board_size) :m_currentBoard(b) , m_BoardSize(board_size) {}


//===============================================

int Board::getBoardSize() const
{
	return m_BoardSize;
}

void Board::printBoard()const
{
	for (size_t i = 0; i < m_BoardSize; i++)
	{
		cout << m_currentBoard[i] << endl;
	}
}

void Board::printToConsole(short charc) const
{
	printBoard();
}

void Board::moveSymbol(Location loc, char symbol)
{
	m_currentBoard[loc.row][loc.col] = symbol;
}

char Board::getTile(Location tile)
{
	return m_currentBoard[tile.row][tile.col];	
}

Location Board::getCellPartner(Location cell)const
{
	for (int i = 0; i < m_cells.size(); i++)
	{
		if (m_cells[i]._cellA.row == cell.row && m_cells[i]._cellA.col == cell.row)
		{
			cell = m_cells[i]._cellB;
			return cell;
		}
		else if (m_cells[i]._cellB.row == cell.row && m_cells[i]._cellB.col == cell.row)
		{
			cell = m_cells[i]._cellA;
			return cell;
		}
	}
	
}