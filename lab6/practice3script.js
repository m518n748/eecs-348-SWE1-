function verifyPassword() {
    const password = document.getElementById("password").value; //get password input value
    const confirmPassword = document.getElementById("confirmPassword").value;
    const message = document.getElementById("message"); 

    if(password === confirmPassword) { //if passwords match
        if(password.length >= 8) { //if password is at least 8 characters long
            message.style.color = "green";
            message.innerHTML = "Password is valid"; //update message
        }

        else { //if password is less than 8 characters long
            message.style.color = "red";
            message.innerHTML = "Password must be at least 8 characters long";
        }
    }
    
    else { //if passwords do not match
        message.style.color = "red";
        message.innerHTML = "Passwords do not match";
    }
}