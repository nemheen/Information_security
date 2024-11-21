This project processes and parses network traffic logs into a structured format for easier analysis. It includes:  

- **Log Parsing**: Converts raw log data into a DataFrame with key fields.  
- **Data Preprocessing**: Cleans and transforms non-numeric, hex, and numeric fields for analysis.  
- **Example Dataset**: A sample log file (`SotM30-anton.log`) is provided for testing.  

### Features  
- Extracts important fields like `SRC`, `DST`, `MAC`, `TTL`, and more.  
- Handles missing values and encodes categorical data.  
- Converts hexadecimal fields to numeric format.  
  
