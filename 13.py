# Creating a Series from list
s = pd.Series([10, 20, 30, 40, 50])
print("Series:\n", s)

# Head (first 5 values)
print("\nHead:\n", s.head())

# Tail (last 5 values)
print("\nTail:\n", s.tail())

# Vector operations (element-wise)
print("\nAdd 5:\n", s + 5)
print("\nMultiply by 2:\n", s * 2)


# ------------------------------------------
# 🔹 2. DATAFRAME (2D DATA STRUCTURE)
# ------------------------------------------

# Creating DataFrame from dictionary
df = pd.DataFrame({
    'Name': ['Ram', 'Shyam', 'Mohan'],
    'Marks': [80, 75, 90]
})

print("\nDataFrame:\n", df)

# Display head and tail
print("\nHead:\n", df.head())
print("\nTail:\n", df.tail())


# ------------------------------------------
# 🔹 3. DATAFRAME OPERATIONS
# ------------------------------------------

# Selecting single column
print("\nSelect Name column:\n", df['Name'])

# Selecting multiple columns
print("\nSelect multiple columns:\n", df[['Name', 'Marks']])

# Adding a new column
df['Grade'] = ['A', 'B', 'A']
print("\nAfter Adding Column:\n", df)

# Deleting a column
df.drop('Grade', axis=1, inplace=True)
print("\nAfter Deleting Column:\n", df)

# Iterating over rows
print("\nIteration:")
for index, row in df.iterrows():
    print(index, row['Name'], row['Marks'])


# ------------------------------------------
# 🔹 4. BINARY OPERATIONS (DF vs DF)
# ------------------------------------------

df1 = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})
df2 = pd.DataFrame({'A': [10, 20, 30], 'B': [40, 50, 60]})

# Element-wise operations
print("\nAddition:\n", df1 + df2)
print("\nSubtraction:\n", df1 - df2)
print("\nMultiplication:\n", df1 * df2)
print("\nDivision:\n", df1 / df2)

