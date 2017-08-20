
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2016 Igor Mironchik

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CHESS__FIGURES_HPP__INCLUDED
#define CHESS__FIGURES_HPP__INCLUDED

// Qt include.
#include <QFlags>
#include <QString>

// C++ include.
#include <array>


namespace Chess {

//
// Move
//

//! Move.
class Move final {
public:
	//! Type of movement.
	enum Type {
		Unknown = 0x00,
		Movement = 0x01,
		Hit = 0x02
	}; // enum Type

	Q_DECLARE_FLAGS( Types, Type )

	//! Distance.
	enum Distance {
		No,
		One,
		Any,
		TwoFirstTime
	}; // enum Distance

	Move( Types t, Distance d );
	~Move();

	//! \return Types.
	Types types() const;

	//! \return Distance.
	Distance dist() const;

private:
	//! Types.
	Types m_types;
	//! Distance.
	Distance m_dist;
}; // class Move


//
// Figure
//

//! Chess figure on the board.
class Figure {
public:
	//! Color.
	enum Color {
		White,
		Black
	}; // enum Color

	enum FigureType {
		KingFigure,
		QueenFigure,
		CastleFigure,
		KnightFigure,
		BishopFigure,
		PawnFigure
	}; // enum FigureType

	Figure( int xv, int yv, Color c, const QString & name,
		int index );
	virtual ~Figure();

	//! Moves.
	using Moves = std::array< std::array< Move, 5 >, 5 >;

	//! \return Possible moves.
	virtual const Moves & moves() const = 0;

	//! \return Type of figure.
	virtual FigureType type() const = 0;

	//! \return Index in the array.
	int index() const;

	//! \return X.
	int x() const;
	//! Set X.
	void setX( int value );

	//! \return Y.
	int y() const;
	//! Set Y.
	void setY( int value );

	//! \return Color.
	Color color() const;

	//! \return Name.
	const QString & name() const;

	//! \return Is first move done?
	bool isFirstMoveDone() const;
	//! Mark figure as did first move.
	void firstMoveDone();

private:
	//! X.
	int m_x;
	//! Y.
	int m_y;
	//! Color.
	Color m_c;
	//! Name.
	QString m_name;
	//! First move has been done.
	bool m_firstMoveDone;
	//! Index in the array.
	int m_index;
}; // class Figure


//
// Pawn.
//

//! Pawn.
class Pawn final
	:	public Figure
{
public:
	Pawn( int xv, int yv, Color c, const QString & n, int index );
	~Pawn();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class Pawn


//
// Castle
//

//! Castle.
class Castle final
	:	public Figure
{
public:
	Castle( int xv, int yv, Color c, const QString & n, int index );
	~Castle();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class Castle


//
// Knight
//

//! Knight.
class Knight final
	:	public Figure
{
public:
	Knight( int xv, int yv, Color c, const QString & n, int index );
	~Knight();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class Knight


//
// Bishop
//

//! Bishop.
class Bishop final
	:	public Figure
{
public:
	Bishop( int xv, int yv, Color c, const QString & n, int index );
	~Bishop();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class


//
// Queen
//

//! Queen.
class Queen final
	:	public Figure
{
public:
	Queen( int xv, int yv, Color c, const QString & n, int index );
	~Queen();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class Queen


//
// King
//

//! King.
class King final
	:	public Figure
{
public:
	King( int xv, int yv, Color c, const QString & n, int index );
	~King();

	//! \return Possible moves.
	const Moves & moves() const;

	//! \return Type of figure.
	FigureType type() const;

private:
	static const Moves m_moves;
}; // class King

} /* namespace Chess */

Q_DECLARE_OPERATORS_FOR_FLAGS( Chess::Move::Types )

#endif // CHESS__FIGURES_HPP__INCLUDED
