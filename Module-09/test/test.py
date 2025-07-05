import csv

# Open the CSV file
with open('datashort.csv', 'r', newline='') as csvfile:
    # Create a csv.reader object
    reader = csv.reader(csvfile)

    # Read the header row (optional)
    header = next(reader)
    print(f"Header: {header}")

    # Iterate over rows and print data
    for row in reader:
        print(row)