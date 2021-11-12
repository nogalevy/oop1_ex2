#include "Board.h"
#include "controller.h"
//#include <filesystem>

//using std::filesystem::current_path;
//#include <unistd.h>

void Board::printToConsole(short charc) const
{
	printBoard();
	//printGameData(charc);
}

Board::Board() :m_BoardSize(0) {}

Board::Board(std::vector <std::string> b, int boardSize) :m_currentBoard(b) , m_BoardSize(boardSize) {}


//template<typename Character>
Board::Board(std::string level)
	: m_currentBoard()
{
	
	//int row, col;
	////char tmp[256];
	////cout << current_path() << endl;
	////std::string level_path = "../../../levels/" + level;
	//auto flevel = ifstream(level);
	//if (!flevel.is_open())
	//{
	//	std::cerr << "Cannont open level file\n";
	//	exit(EXIT_FAILURE);
	//}

	//auto line = std::string();
	//auto numOfLines = std::string();
	//

	//std::getline(flevel, numOfLines);
	//m_BoardSize = std::stoi(numOfLines);
	//m_currentBoard.reserve(m_BoardSize);

	//for (size_t i = 0; i < m_BoardSize; i++)
	//{
	//	std::getline(flevel, line);//get line
	//	m_currentBoard.push_back(line);//push to end of file the line
	//}


	/*
	for (int i = 0; i < NUM_OF_CHARACTERS; i++)
	{
		flevel >> row >> col;
		//Character charc = c.getActiveCharacter();
		c.setCharacterLocation(Location(row, col));
		c.changeActiveCharacter();
	}
	
	//read teleport cells
	int num_of_cells;
	flevel >> num_of_cells;
	int row1, col1, row2, col2;
	m_cells.reserve(num_of_cells);

	for (int j = 0; j < num_of_cells; j++)
	{
		flevel >> row1 >> col1 >> row2, col2;
		//m_cells.push_back(Teleport(Location(row1,col1), Location(row2, col2)));
	}*/
}

int Board::getBoardSize() const
{
	return m_BoardSize;
}

void Board::printBoard()const
{
	/*
	for (size_t i = 0; i < m_currentBoard.size(); i++)
	{
		cout << m_currentBoard[i] << endl;
	}*/
	for (size_t i = 0; i < m_BoardSize; i++)
	{
		cout << m_currentBoard[i] << endl;
	}
}

//
//void Board::printGameData(short charc) const
//{
//	switch (charc)
//	{
//	case KING:
//		cout << "king   ";
//		break;
//	case MAGE:
//		cout << "mage    ";
//		break;
//
//	case THEIF:
//		cout << "theif   ";
//		break;
//
//	case WARRIOR:
//		cout << "warrior   ";
//		break;
//
//	default:
//		break;
//	}
//	//cout << "Current Active Character: " << c.getActiveCharacterName() << endl;
//	//cout << "Sum of number of steps: " << c.getSteps() << endl;
//	/*cout << "The Theif ";
//	(c.theifHasKey()) ? cout << "has " : cout << "does not have ";
//	cout << "the key.\n";*/
//}

void Board::moveSymbol(Location loc, char symbol)
{
	m_currentBoard[loc.row][loc.col] = symbol;
}

char Board::getTile(Location tile)
{
	//int i = m_currentBoard.size(); // !!
	
	//std::string curr_row = m_currentBoard[tile.row];
	//if (tile.row > 9 || tile.row < 0 || tile.col > 9 || tile.col < 0) return '=';
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