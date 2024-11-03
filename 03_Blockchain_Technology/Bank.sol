// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    address public owner;
    mapping(address => uint) private balance;

    constructor(){
        owner = msg.sender;
    }

    function deposit(uint amount) public {
        if(amount < 0){
            revert("Amount should be positive");
        }
        balance[msg.sender] += amount;

    }

    function withdraw(uint amount) public{
        if(balance[msg.sender] < amount){
            revert("Cannot withdraw money as balance is lower than amount to be withdrawn");
        }
        balance[msg.sender] -= amount;
    }
    

    function showBalance() public view returns (uint){
        return balance[msg.sender];
    }
}
