document.querySelector('#registrationForm').addEventListener(
    'submit',
    (event) => {
        event.preventDefault();

        let firstName = document.getElementById('firstName').value;
        let lastName = document.getElementById('lastName').value;
        let email = document.getElementById('email').value;
        let mobile = document.getElementById('mobile').value;
        let dob = document.getElementById('dob').value;
        let state = document.getElementById('state').value;
        let city = document.getElementById('city').value;
        let pincode = document.getElementById('pincode').value;
        let password = document.getElementById('password').value;
        let confirmPassword = document.getElementById('confirmPassword').value;

        const namePattern = /^[A-Za-z]+$/;
        const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        const passwordPattern = /^(?=.*[A-Za-z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{6,}$/;

        if (!namePattern.test(firstName) || !namePattern.test(lastName)) 
        {
            alert('Name cannot contain numbers or special characters.');
            return;
        }
        if (!emailPattern.test(email)) 
        {
            alert('Invalid email format.\neg. name@domain.com');
            return;
        }
        if (mobile.length !== 10) 
        {
            alert('Mobile number must be 10 digits.');
            return;
        }
        if (!dob) 
        {
            alert('Please enter you Date of Birth.');
            return;
        }
        if (!city || !state) 
        {
            alert('Please enter your valid State and City.');
            return;
        }
        if (!pincode.match(/^\d{6}$/))
        {
            alert('Pincode must be 6 digits.');
            return;
        }
        if (!passwordPattern.test(password)) 
        {
            alert('Password must be at least 6 characters long and contain letters, numbers, and special characters.');
            return;
        }
        if (password !== confirmPassword) 
        {
            alert('Passwords do not match.');
            return;
        }

        console.log("User is registerred Successfully!");
        alert('Registration successful!');

        document.getElementById('registrationForm').reset();
    }
);