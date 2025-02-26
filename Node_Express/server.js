const express = require('express');
const bodyParser = require('body-parser');
const mysql = require('mysql');
const cors = require('cors');
const app = express();
const port=5501;

  

app.use(bodyParser.json());
app.use(cors());

  

const db = mysql.createConnection({
    host: 'localhost',
    user:  'root',
    password: "",
    database: 'mydata',
    port:'3306'

});

db.connect((err) => {
    if (err) {
        console.error('Error connecting to MySQL database: ' + err.stack);
        return;
    }
    console.log('Connected to MySQL database');
});

app.post('/saveData', (req, res) => {
  //const { value1, value2 } = req.body;
    const value1=req.body.timi1;
    const value2=req.body.timi2;
    debugger;

    const insertQuery = 'INSERT INTO saves (value1, value2) VALUES (?, ?)';
    db.query(insertQuery, [value1, value2], (err, result) => {
        if (err) {
            return res.status(500).json({ message: 'Error saving to database' });
        }
        res.json({ message: 'Data saved successfully!' });
    });
});

app.get('/keyRet', (req, res) => {
    //const search = req.params.synth;

    // Ερώτημα για την ανάκτηση μόνο της στήλης "name" από τον πίνακα σας, χρησιμοποιώντας τη μεταβλητή category
    const query = `SELECT * FROM saves `; // Αντικαταστήστε το your_table με το όνομα του πίνακα σας

    db.query(query,(err, result) => {
        if (err) {
            res.status(500).json({ message: 'Error fetching data' });
        } else {
            res.status(200).json(result);
        }
    });
});



app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}`);
});
