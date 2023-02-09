# Welcome to My Blockchain
***

## Task
Welcome to My Blosckchain

## Description

Blockchain is a command that allows for the creation and management of a blockchain. When the program starts (it loads a backup if there is one) then a prompt appears.
This prompt allows to execute commands. When the commands are successful they display "ok" and if not, "nok: info" or info is an error message - see below:

add node nid add a nid identifier to the blockchain node.
rm node nid... remove nodes from the blockchain with a nid identifier. If nid is '*', then all nodes are impacted.
add block bid nid... add a bid identifier block to nodes identified by nid. If nid is '*', then all nodes are impacted.
rm block bid... remove the bid identified blocks from all nodes where these blocks are present.
ls list all nodes by their identifiers. The option -l attaches the blocks bid's associated with each node.
sync synchronize all of the nodes with each other. Upon issuing this command, all of the nodes are composed of the same blocks.
quit save and leave the blockchain.
The blockchain prompt must display (see example below):

a [ character
a first letter that indicates the state of synchronization of the chain:
"s" if the blockchain is synchronized
"-" if the blockchain is not synchronized.
n number of nodes in the chain.
the "]> " string (with a space)
Error messages
1: no more resources available on the computer
2: this node already exists
3: this block already exists
4: node doesn't exist
5: block doesn't exist
6: command not found
Technical Information
$>my_blockhain
No Backup Found: Starting New Blockchain
[s0]> add node 12
OK
[s1]> add block 21 *
OK
[s1]> add node 13
OK
[-2]> sync
OK
[s2]> ls -l
12: 21
13: 21
[s2]> quit
Backing up blockchain...
$>my_blockhain
Restoring From Backup
[s2]> ls -l
12: 21
13: 21
[s2]>

## Installation
Makefile

## Usage

```
./my_blockhain

[s0]> add node 12
OK
[s1]> add block 21 *
OK
[s1]> add node 13
OK
[-2]> sync
OK
[s2]> ls -l
12: 21
13: 21
[s2]> quit
Backing up blockchain...
$>my_blockhain
Restoring From Backup
[s2]> ls -l
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
