#### git is awesome
git is awesome for reasons i cannot state here 


### Use case
- 1.Submit paper .
- 2.Verify researcher’s paper .
- 3.Verify Senior Researcher’s paper .
- 4.Create account .
- 5.Create admin account .
- 6.Make a comment .
- 7.Notify Admin .
- 8.Notify Researcher .
- 9.Notify Senior Researcher .
- 10.Notify Executive Director .
- 11.Evaluate Employees .

### Function Requirement
- 1.System should manage user authentication and account verification .
- 2.System should manage files by allowing researcher and senior researcher to submit papers .
- 3.The system should evaluate researcher ,senior researcher and administrators on a regular basis .
- 4.The system should enable a senior researcher to verify a researchers papers and publication .
- 5.The system should enable an executive director to verify a senior researchers papers and publications .
- 6.System should support feedback and notification of users on accomplishment of some tasks such as file management .
- 7.The system must be able to log and process complaints from researchers and senior researchers with regards to the work of administrators .

### Validation and verification plan :

| Test name   | Functional Requirement | Use case | Test condition question test | Expected outcome hypothesis |
|-------------|------------------------|----------|------------------------------|-----------------------------|
|             | FR1                    | UC4 ,UC5 | -User enter his/her details .  | -If user is an employee the account should be created and stored on the database where it can be read later.-If user is not an employee the account should not be crated and not stored on the database .|
|             | FR2                    | UC1      | -User selects and upload their paper . | -The paper should be opened and viewed in the users account . -The should be accessed by the person who is supposed to verify the paper . |                             