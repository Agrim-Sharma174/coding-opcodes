0x6080604052348015600f57600080fd5b5060ac8061001e6000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c8063cdfead2e146037578063e026c017146049575b600080fd5b60476042366004605e565b600055565b005b60005460405190815260200160405180910390f35b600060208284031215606f57600080fd5b503591905056fea2646970667358221220e160f0a9b49ebe28c710ff8b219fcb167b856863ea93e4ebd58bfd2744f5549664736f6c63430008140033

// 3 sections in total-
//     1. contract creation
//     2. runtime (actually gets stored in the blockchain)
//     3. metadata (tells about compiler version i have used or any other metadata)

// 1. contract creation code

// free memory pointer
PUSH1 0x80      // [0x80]
PUSH1 0x40      // [0x40, 0x80]
MSTORE          // []           // Memory 0x40 -> 0x80

// If someone sent value with this call revert! Otherwise, jump, to continue execution
CALLVALUE       // [msg.value] // 2:48
DUP1            // [msg.value, msg.value]
ISZERO          // [msg.value == 0, msg.value]
PUSH1 0x0f      // [0x0F, msg.value == 0, msg.value]
JUMPI           // [msg.value] 
PUSH1 0x00      // [0x00, msg.value]
DUP1            // [0x00, 0x00, msg.value]
REVERT          // [msg.value]

// Jump dest if msg.value == 0
// sticks run time code on chain
JUMPDEST        // [msg.value]
POP             // []
PUSH1 0xac      // [0xAC]
DUP1            // [0xAC, 0xAC]
PUSH2 0x001e    // [0x001E, 0xAC, 0xAC]
PUSH1 0x00      // [0x00, 0x001E, 0xAC, 0xAC]
CODECOPY        // [0xAC]                       //Memory: [runtime code]
PUSH1 0x00      // [0x00, 0xa5]
RETURN          // []
INVALID         // []

// 2. Runtime code
// Entry point of all calls
// free memory pointer
PUSH1 0x80
PUSH1 0x40
MSTORE

// checking msg.value, if given, revert
CALLVALUE       // [msg.value]
DUP1            // [msg.value, msg.value]
ISZERO          // [msg.value == 0, msg.value]
PUSH1 0x0f      // [0x0F, msg.value == 0, msg.value]
JUMPI           // [msg.value]
// jump to continue, if msg.value == 0

PUSH1 0x00      // [0x00, msg.value] 
DUP1            // [0x00, 0x00, msg.value] 
REVERT          // [msg.value]

// if msg.value == 0, start here
// continue
JUMPDEST        // [msg.value]
POP             // []
PUSH1 0x04      // [0x04]
CALLDATASIZE    // [calldata_size, 0x04]
LT
PUSH1 0x32
JUMPI
PUSH1 0x00
CALLDATALOAD
PUSH1 0xe0
SHR
DUP1
PUSH4 0xcdfead2e
EQ
PUSH1 0x37
JUMPI
DUP1
PUSH4 0xe026c017
EQ
PUSH1 0x49
JUMPI
JUMPDEST
PUSH1 0x00
DUP1
REVERT
JUMPDEST
PUSH1 0x47
PUSH1 0x42
CALLDATASIZE
PUSH1 0x04
PUSH1 0x5e
JUMP
JUMPDEST
PUSH1 0x00
SSTORE
JUMP
JUMPDEST
STOP
JUMPDEST
PUSH1 0x00
SLOAD
PUSH1 0x40
MLOAD
SWAP1
DUP2
MSTORE
PUSH1 0x20
ADD
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN
JUMPDEST
PUSH1 0x00
PUSH1 0x20
DUP3
DUP5
SUB
SLT
ISZERO
PUSH1 0x6f
JUMPI
PUSH1 0x00
DUP1
REVERT
JUMPDEST
POP
CALLDATALOAD
SWAP2
SWAP1
POP
JUMP
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
INVALID
PUSH1 0xf0
INVALID
INVALID
SWAP15
INVALID
INVALID
INVALID
LT
SELFDESTRUCT
DUP12
INVALID
SWAP16
INVALID
AND
PUSH28 0x856863ea93e4ebd58bfd2744f5549664736f6c63430008140033