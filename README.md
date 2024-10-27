# Airgead Banking App C++

**Summary:** The Airgead Banking App is developed to track investments over time, with and without additional monthly deposits. The primary goal of this project is to provide users with a clear understanding of how their initial investment grows over time based on annual interest rates, with the option to include monthly contributions.

For instance, the project involves creating a system that calculates the annual interest and overall balance for a user’s investment, both with and without monthly deposits. This helps address issues such as financial planning and investment tracking by providing users with an idea of how much they can expect for future growth based on various inputs like initial investment amount, monthly contributions, and interest rates. The project is implemented using object-oriented programming and file handling.

**What Did I Do Particularly Well?**
In this project, I wrote concise comments for the code. Each function is explained, making the code easier to understand. For example, I added comments that clarify the purpose of different variables and loops. This helps with readability for others who are viewing the code. Additionally, the program is user-friendly by prompting for valid inputs and displaying tables for the output. This is done for both investment growth with and without monthly deposits. The input checks ensure that the user cannot enter invalid values, such as negative numbers. The output tables are formatted with column headers, proper spacing, and decimal places, allowing users to view their year-end balances and interest earned each year.

**Where Could You Enhance Your Code? How Would These Improvements Make Your Code More Efficient, Secure, and So On?**
An area where I could improve my code is optimizing the loop that calculates interest for investments with monthly deposits. Currently, the calculation is done using a simple loop for each month, but using a different algorithm could make the program more efficient, especially for larger numbers of years or higher deposit amounts. These improvements would make the code faster and improve performance.

**Challenging:**
The most challenging part of this project was making sure the interest calculations for the monthly deposits were accurate. Calculating the interest for each month while updating the balance required careful thought. To solve this, I referred back to the Airgead Banking Standards and the requirements. I also viewed online guides to learn how to handle these calculations.

**Transferable Skills:**
The skills I learned from this project can be used in other finance-related projects or any assignments that need calculations. Breaking down problems into smaller parts will help me in future projects like this. For example, putting interest calculations in separate functions. I also improved my ability to handle user inputs and make sure the program responds correctly to any errors.

**Maintainability, Readability, and Adaptability:**
To make this program maintainable, I used an object-oriented approach. For example, the Investment class keeps all data relevant to the investment calculations, making it easy to update in the future if there are additional features I want to add. The code is readable because of the use of comments, which help explain what the code does. Lastly, the code is adaptable because it can be extended to handle additional investment types or more complex situations.
