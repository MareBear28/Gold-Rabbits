# Gold-Rabbits 🐇
Gold-Rabbits estimates how many rabbits will there be in 10 years.

# Rules for Gold Rabbits 💡
1. New-born rabbits take one month to mature
2. One pair of mature rabbits will have a pair of baby rabbits after one month
3. Mature rabbits will continue to produce a new pair of baby rabbits every month
4. Rabbits never die

Example:
- At the start of month 0, I receive the baby rabbits so I have 1 pair of rabbits.
- At the start of month 1, the baby rabbits are grown and the female becomes pregnant. But I still have only 1 pair of rabbits.
- At the start of month 2, the first pair give birth to 1 pair of rabbits, so now I have 2 pairs of rabbits. The first pair (the adults) immediately become pregnant again.
- At the start of month 3, the second pair is now mature and the first pair give birth again to 1 pair of rabbits. This gives me 3 pairs of rabbits.
- At the start of month 4, the first pair gives birth to a new pair, the second pair gives birth to a new pair, and the third pair are all grown up and ready to start family life. So now I have 5 pairs of rabbits.

## Goals ⭐
- Write the goldRabbits(int n) function that throws an exception if interget overflows. Exception will throw a string that indicates the input number (n) which cause the overflow.
- Create a new Class called BigInt that will allow calculating goldRabbits(120), or even goldRabbits(2000)
- Modify the function goldRabbits so that it can also calculate goldRabbits(2000) before we all die.