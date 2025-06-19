import pandas as pd

# Load the file (change path/filename as needed)
df = pd.read_csv("D:\ALGORITHM\PYTHON\pandas\TPO_DATA_2024_25.csv")  # or pd.read_csv("filename.csv")

# Display first 10 rows
print("First 10 Rows:")
print(df.head(10))

# Display summary statistics (only for numeric columns)
print("\nSummary Statistics:")
print(df.describe())

# Display full info about the DataFrame
print("\nDataFrame Info:")
print(df.info())
