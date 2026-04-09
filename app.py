from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def valeur():
    return render_template('index.html')

@app.route('/submit-data', methods=['POST'])
def handle_data():
    # 'user_choice' matches the 'name' attribute in your HTML input
    fahr = request.form.get('temp')
    fahr = int(fahr)
    return f"{fahr} fahrenheit correspond à {(fahr - 32) * 5 / 9} celsius"



