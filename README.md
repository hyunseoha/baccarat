# baccarat
I made a baccarat game as my first C++ home project.

The code goes this way.

52 Cards are built up.
10 and above count as 0 and 1 to 9 count as they are.

The random numbers are stored in the vector and the length is 52.
If you want to use double card or triple card as real casions, then you have to change 52 Cards to 52 * 2 or 52 * 3.
Of course the random number has to be modified as well.

You can decide your deposit as the betting deposit.

You bet the money on player or banker and on TIE.

The cards are draw and the first card is given to player and the second given to banker.
third and fourth are given to each other as the same way.

The score is computed and the payout is made.

# Deck Build-Up
It was difficult to remove the drawn cards from the shoe, so I randomly built up the deck first,
and then show the cards as player and banker side. You would understand what I say, if you play once.

# Change the number of repeat.
Line 66 there is [rounds] integer. you can change this number to change the number of rounds of the game.
It should give you error message after 12th round, because there are no more remaining random deck.

# Betting rules
It follows simple bet rules.
Your bet corrects on banker or player, then you get double the bet. But Banker bet lose 5% as commission.
TIE bet pays you 8 times as usual.

Have fun !

## Next Game
I am planning to code Kniffel.
https://de.wikipedia.org/wiki/Kniffel

