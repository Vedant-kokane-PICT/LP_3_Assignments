// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    address public owner;
    uint balance;


    function deposit(uint amount) public {
        if(amount < 0){
            revert("Amount should be positive");
        }
        balance += amount;

    }

    function withdraw(uint amount) public{
        if(balance < amount){
            revert("Cannot withdraw money as balance is lower than amount to be withdrawn");
        }
        balance -= amount;
    }
    

    function showBalance() public view returns (uint){
        return balance;
    }
}
