// SPDX-License-Identifier: MIT
pragma solidity ^0.8.22;

contract StudentData {
    struct Student {
        string name;
        int age;
    }

    Student[] public studentArray;

    // Add new student details to the array
    function addStudent(string memory name, int age) public {
        for (uint i = 0; i < studentArray.length; i++) {
            if (studentArray[i].age == age) {
                revert("Roll No Exists");
            }
        }
        studentArray.push(Student(name, age));
    }

    // Returns all students in the array
    function displayAllStudents() public view returns (Student[] memory) {
        return studentArray;
    }

    // Returns the length of the student array
    function getStudentLength() public view returns (uint256) {
        return studentArray.length;
    }

    // Get a student by index
    function getStudent(uint128 index) public view returns (Student memory) {
        require(studentArray.length > index, "Out of Index");
        return studentArray[index];
    }

    // Fallback function for handling unknown function calls
    fallback() external payable {
        // Optionally, handle the call or log it
    }

    // Receive function for handling direct ETH transfers
    receive() external payable {
        // Handle ETH transfers to the contract
    }
}