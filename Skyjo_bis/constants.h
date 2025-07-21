#pragma once  
#include <map>  

namespace Constants {  
   namespace Card {  
       // CARD_FREQUENCY cannot be constexpr because std::map is not a literal type.  
       // Instead, we use const to ensure immutability.  
       const std::map<int, unsigned int> CARD_FREQUENCY = {  
           {-2, 5},  
           {-1, 10},  
           {0, 15},  
           {1, 10},  
           {2, 10},  
           {3, 10},  
           {4, 10},  
           {5, 10},  
           {6, 10},  
           {7, 10},  
           {8, 10},  
           {9, 10},  
           {10, 10},  
           {11, 10},  
           {12, 10},  
       };  

       // Define CARD_NUMBER as a constexpr since it can be evaluated at compile time.  
       constexpr unsigned int CARD_NUMBER = 144;
   }

   namespace Deck {
	   constexpr unsigned int N_ROW = 3;
	   constexpr unsigned int N_COL = 4;
   }

   namespace Game
   {
       constexpr unsigned int MIN_PLAYER_AMOUNT = 2;
       constexpr unsigned int MAX_PLAYER_AMOUNT = 8;
   }
}