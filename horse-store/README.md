# Horse Store

1. Write a simplestorage/horsestore
--
differentialy testing or differentialy fuzzing is when we write tests for 2 files, having totally different file types like .sol or .huff

I ran the code in `HorseStore.sol` in remix and then i called updateHorseNumber with an input `1`, i got this in `input` when i clicking in terminal, the below button. This thing is calldata and it tells smart contract that this is what i want you to do.
0xcdfead2e0000000000000000000000000000000000000000000000000000000000000001 

1. How did this data come form? How did remix know to send this data?
2. How does remix know to update the number of horses with this data?

we'll answer this by learning huff

function signature- updateHorseNumber(uint256) and we will hash them- it will become function selector
i will do cast sig "updateHorseNumber(uint256)"
i got this- 0xcdfead2e (look above, this is short version of that calldata, first part of that calldata)- this is function selector- first 4 bytes
this is called function dispatching- solidity knows to take first 4 bytes of calldata and use it to pick which func we are refering to

let's do cast sig "readNumberOfHorses()"- we got 0xe026c017

Functiondispatch(method dispatch) is the algowithm used to determine which functions/commands should be run/invoked in response to a message. In EVM, this is when a smart contract used the first 4 bytes of calldata to determine which func(which is a group of opcodes) to send the calldata to.

what if we write in opcodes directly, we can manually call yay... which we will write in HUFF

