    for (i = 0; i < columns; i++)
        *(array + i) = new int[rows];
    b = columns * rows;
    while (k <= columns * rows)
    {
        for (j = c; j < rows - c; j++)
        {
            if (k > b)
                break;
            array[c][j] = k++;
        }
        for (i = c + 1; i < columns - c; i++)
        {
            if (k > b)
                break;
            array[i][rows - c - 1] = k++;
        }
        for (j = rows- c - 2; j >= c; j--)
        {
            if (k > b)
                break;
            array[columns - c - 1][j] = k++;
        }
        for (i = columns - c - 2; i > c; i--)
        {
            if (k > b)
                break;
            array[i][c] = k++;
        }
        c++;
    }
    for (i = 0; i < columns; i++)
    {
        for (j = 0; j < rows - 1; j++)
            if (array[i][j] < 10) {
                cout << array[i][j] << "  ";
            }
            else {
                cout << array[i][j] << " ";
            }
        cout << array[i][rows - 1] << "\n";
    }
