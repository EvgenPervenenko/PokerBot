#ifndef ENTITIES_CARD_H
#define ENTITIES_CARD_H

namespace Entities {
	
	enum class Rank : unsigned short
	{
		Undefind = 0,
		Two = 2, 
		Three, 
		Four, 
		Five, 
		Six, 
		Seven, 
		Eight, 
		Nine, 
		Ten, 
		Jack, 
		Queen, 
		King, 
		Ace
	};
	
	enum class Suit : unsigned short
	{
		Undefind = 0, 
		Heart, 
		Dimond, 
		Spade, //♠
		Clubs// ♣
	};
	
	class Card
	{
	public:
		Card();
		Card( Rank, Suit );
		~Card();
		
		Rank GetRank() const;
		Suit GetSuit() const;
		
		void SetRank(Rank rank);
		void SetSuit(Suit suit);
		
	private:
		Rank _rank;
		Suit _suit;
	};
	
} // namespace Entities

#endif // ENTITIES_CARD_H
