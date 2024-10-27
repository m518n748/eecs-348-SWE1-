<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    
    <title>Matthew's Practice 4</title>
    <!--css for table styling -->
    <style>
        table, th, td { /*th: table header, td: table data */
            border: 1px solid black;
            border-collapse: collapse;
            padding: 8px;
            text-align: center;
        }
    </style>
</head>
<body>
    <h1>Multiplication table with PHP</h1>
    <!--form for receiving user input--> 
    <form method="POST"> 
        <label for="number">Enter a number:</label>
        <input type="number" id="number" name="number" min="1" required>
        <button type="submit">Generate Table</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") { // if form is submitted
        $num = intval($_POST["number"]); // get user input

        echo "<h2>Multiplication Table up to $num</h2>";
        echo "<table>";

        
        echo "<tr><th>*</th>";
        for ($i = 1; $i <= $num; $i++) { // table for each column index
            echo "<th>$i</th>";
        }
        echo "</tr>";

        
        for ($row = 1; $row <= $num; $row++) { // table for each row index
            echo "<tr><th>$row</th>";  
            for ($col = 1; $col <= $num; $col++) {
                echo "<td>" . ($row * $col) . "</td>";  
            }
            echo "</tr>";
        }
        echo "</table>"; // close table
    }
    ?>

</body>
</html>