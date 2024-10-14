// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
     // Mapping to store the balance of each account holder (address)
    mapping(address => uint256) private balances;

    // Event to log deposits
    event Deposit(address indexed account, uint256 amount);

    // Event to log withdrawals
    event Withdraw(address indexed account, uint256 amount);

    // Deposit function to add money to the sender's account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than zero.");
        balances[msg.sender] += msg.value;
        emit Deposit(msg.sender, msg.value);
    }

    // Withdraw function to withdraw money from the sender's account
    function withdraw(uint256 withdrawAmount) public {
        require(balances[msg.sender] >= withdrawAmount, "Insufficient balance.");
        balances[msg.sender] -= withdrawAmount;
        payable(msg.sender).transfer(withdrawAmount);
        emit Withdraw(msg.sender, withdrawAmount);
    }

    // Function to check the balance of the sender's account
    function checkBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}