/* =========================================================
   BANKING SYSTEM DATA
========================================================= */

let accounts =
    JSON.parse(localStorage.getItem("myBankAccounts")) || [];

let currentAccountIndex =
    localStorage.getItem("myBankCurrentAccount");

if (currentAccountIndex !== null) {
    currentAccountIndex = Number(currentAccountIndex);
}


/* =========================================================
   SAVE DATA
========================================================= */

function saveAccounts() {

    localStorage.setItem(
        "myBankAccounts",
        JSON.stringify(accounts)
    );

}


/* =========================================================
   LOGIN / CREATE ACCOUNT TABS
========================================================= */

function showLogin() {

    document
        .getElementById("loginForm")
        .classList.remove("hidden");

    document
        .getElementById("createForm")
        .classList.add("hidden");


    document
        .getElementById("loginTab")
        .classList.add("active");

    document
        .getElementById("createTab")
        .classList.remove("active");


    document
        .getElementById("authTitle")
        .textContent = "Welcome back";


    document
        .getElementById("authSubtitle")
        .textContent =
        "Login to access your account.";


    clearMessage();
}


function showCreateAccount() {

    document
        .getElementById("loginForm")
        .classList.add("hidden");

    document
        .getElementById("createForm")
        .classList.remove("hidden");


    document
        .getElementById("loginTab")
        .classList.remove("active");

    document
        .getElementById("createTab")
        .classList.add("active");


    document
        .getElementById("authTitle")
        .textContent =
        "Create your account";


    document
        .getElementById("authSubtitle")
        .textContent =
        "Open your personal account in a few steps.";


    clearMessage();
}


/* =========================================================
   MESSAGES
========================================================= */

function showMessage(elementId, text, type) {

    const element =
        document.getElementById(elementId);

    element.textContent = text;

    element.className =
        "message " + type;
}


function clearMessage() {

    const message =
        document.getElementById("authMessage");

    message.className = "message";

    message.textContent = "";
}


/* =========================================================
   CREATE ACCOUNT
========================================================= */

document
    .getElementById("createForm")
    .addEventListener(
        "submit",
        function(event) {

            event.preventDefault();


            const name =
                document
                    .getElementById("createName")
                    .value
                    .trim();


            const accountNumber =
                document
                    .getElementById("createAccount")
                    .value
                    .trim();


            const pin =
                document
                    .getElementById("createPin")
                    .value
                    .trim();


            const balance =
                Number(
                    document
                        .getElementById("createBalance")
                        .value
                );


            /* PIN CHECK */

            if (!/^\d{4}$/.test(pin)) {

                showMessage(
                    "authMessage",
                    "PIN must contain exactly 4 numbers.",
                    "error"
                );

                return;
            }


            /* BALANCE CHECK */

            if (
                balance < 0 ||
                Number.isNaN(balance)
            ) {

                showMessage(
                    "authMessage",
                    "Please enter a valid initial balance.",
                    "error"
                );

                return;
            }


            /* ACCOUNT NUMBER CHECK */

            const exists =
                accounts.some(
                    account =>
                        account.accountNumber ===
                        accountNumber
                );


            if (exists) {

                showMessage(
                    "authMessage",
                    "Account number already exists.",
                    "error"
                );

                return;
            }


            /* CREATE ACCOUNT */

            const newAccount = {

                name: name,

                accountNumber:
                    accountNumber,

                pin: pin,

                balance: balance,

                transactions: []

            };


            accounts.push(newAccount);

            saveAccounts();


            showMessage(
                "authMessage",
                "Account created successfully! You can now login.",
                "success"
            );


            document
                .getElementById("createForm")
                .reset();


            setTimeout(
                showLogin,
                1200
            );

        }
    );


/* =========================================================
   LOGIN
========================================================= */

document
    .getElementById("loginForm")
    .addEventListener(
        "submit",
        function(event) {

            event.preventDefault();


            const accountNumber =
                document
                    .getElementById("loginAccount")
                    .value
                    .trim();


            const pin =
                document
                    .getElementById("loginPin")
                    .value
                    .trim();


            const index =
                accounts.findIndex(
                    account =>
                        account.accountNumber ===
                            accountNumber &&
                        account.pin === pin
                );


            if (index === -1) {

                showMessage(
                    "authMessage",
                    "Invalid account number or PIN.",
                    "error"
                );

                return;
            }


            currentAccountIndex = index;


            localStorage.setItem(
                "myBankCurrentAccount",
                index
            );


            document
                .getElementById("loginForm")
                .reset();


            openDashboard();

        }
    );


/* =========================================================
   OPEN DASHBOARD
========================================================= */

function openDashboard() {

    document
        .getElementById("authPage")
        .classList.add("hidden");


    document
        .getElementById("dashboardPage")
        .classList.remove("hidden");


    updateDashboard();
}


/* =========================================================
   UPDATE DASHBOARD
========================================================= */

function updateDashboard() {

    const account =
        accounts[currentAccountIndex];

    if (!account) {
        return;
    }


    document
        .getElementById("welcomeText")
        .textContent =
        "Welcome back, " +
        account.name +
        " 👋";


    document
        .getElementById("navUserName")
        .textContent =
        account.name;


    document
        .getElementById("dashboardAccount")
        .textContent =
        account.accountNumber;


    document
        .getElementById("balanceDisplay")
        .textContent =
        formatCurrency(account.balance);


    renderRecentTransactions();
}


/* =========================================================
   CURRENCY
========================================================= */

function formatCurrency(amount) {

    return new Intl.NumberFormat(
        "en-IN",
        {
            style: "currency",
            currency: "INR",
            maximumFractionDigits: 2
        }
    ).format(amount);
}


/* =========================================================
   TRANSACTION HISTORY
========================================================= */

function renderRecentTransactions() {

    const container =
        document
            .getElementById("recentTransactions");


    const account =
        accounts[currentAccountIndex];


    const transactions =
        account.transactions
            .slice(-5)
            .reverse();


    if (transactions.length === 0) {

        container.innerHTML =
            '<div class="empty-state">' +
            'No transactions yet.' +
            '</div>';

        return;
    }


    container.innerHTML =
        transactions
            .map(transactionHTML)
            .join("");
}


function transactionHTML(transaction) {

    const isDeposit =
        transaction.type === "Deposit";


    return `

        <div class="transaction">

            <div class="transaction-left">

                <div class="transaction-icon">
                    ${isDeposit ? "↓" : "↑"}
                </div>

                <div>

                    <div class="transaction-type">
                        ${transaction.type}
                    </div>

                    <div class="transaction-date">
                        ${transaction.date}
                    </div>

                </div>

            </div>

            <strong
                class="${isDeposit ? "deposit" : "withdrawal"}">

                ${isDeposit ? "+" : "-"}

                ${formatCurrency(transaction.amount)}

            </strong>

        </div>
    `;
}


function addTransaction(type, amount) {

    const account =
        accounts[currentAccountIndex];


    account.transactions.push({

        type: type,

        amount: amount,

        date:
            new Date()
                .toLocaleString("en-IN")

    });


    saveAccounts();
}


/* =========================================================
   DEPOSIT
========================================================= */

function openDeposit() {

    openModal(
        "Deposit Money",

        `

        <div class="form-group">

            <label>
                Amount to deposit
            </label>

            <input
                type="number"
                id="transactionAmount"
                min="1"
                placeholder="Enter amount">

        </div>


        <button
            class="btn btn-primary full-btn"
            onclick="depositMoney()">

            Deposit Money

        </button>

        `
    );
}


function depositMoney() {

    const input =
        document
            .getElementById("transactionAmount");


    const amount =
        Number(input.value);


    if (
        !Number.isFinite(amount) ||
        amount <= 0
    ) {

        showModalMessage(
            "Please enter a valid amount.",
            "error"
        );

        return;
    }


    accounts[currentAccountIndex]
        .balance += amount;


    addTransaction(
        "Deposit",
        amount
    );


    updateDashboard();


    showModalMessage(
        "Deposit successful!",
        "success"
    );


    setTimeout(
        closeModal,
        900
    );
}


/* =========================================================
   WITHDRAW
========================================================= */

function openWithdraw() {

    openModal(
        "Withdraw Money",

        `

        <div class="form-group">

            <label>
                Amount to withdraw
            </label>

            <input
                type="number"
                id="transactionAmount"
                min="1"
                placeholder="Enter amount">

        </div>


        <button
            class="btn btn-primary full-btn"
            onclick="withdrawMoney()">

            Withdraw Money

        </button>

        `
    );
}


function withdrawMoney() {

    const amount =
        Number(
            document
                .getElementById("transactionAmount")
                .value
        );


    const account =
        accounts[currentAccountIndex];


    if (
        !Number.isFinite(amount) ||
        amount <= 0
    ) {

        showModalMessage(
            "Please enter a valid amount.",
            "error"
        );

        return;
    }


    if (amount > account.balance) {

        showModalMessage(
            "Insufficient balance.",
            "error"
        );

        return;
    }


    account.balance -= amount;


    addTransaction(
        "Withdrawal",
        amount
    );


    updateDashboard();


    showModalMessage(
        "Withdrawal successful!",
        "success"
    );


    setTimeout(
        closeModal,
        900
    );
}


/* =========================================================
   SHOW ALL TRANSACTIONS
========================================================= */

function showTransactions() {

    const account =
        accounts[currentAccountIndex];


    const transactions =
        account.transactions
            .slice()
            .reverse();


    let content = "";


    if (transactions.length === 0) {

        content =
            '<div class="empty-state">' +
            'No transactions yet.' +
            '</div>';

    } else {

        content =
            transactions
                .map(transactionHTML)
                .join("");
    }


    openModal(
        "Transaction History",
        content
    );
}


/* =========================================================
   CHANGE PIN
========================================================= */

function openChangePin() {

    openModal(
        "Change PIN",

        `

        <div class="form-group">

            <label>
                Current PIN
            </label>

            <input
                type="password"
                id="oldPin"
                maxlength="4"
                inputmode="numeric"
                placeholder="Current PIN">

        </div>


        <div class="form-group">

            <label>
                New PIN
            </label>

            <input
                type="password"
                id="newPin"
                maxlength="4"
                inputmode="numeric"
                placeholder="New 4 digit PIN">

        </div>


        <button
            class="btn btn-primary full-btn"
            onclick="changePin()">

            Update PIN

        </button>

        `
    );
}


function changePin() {

    const oldPin =
        document
            .getElementById("oldPin")
            .value
            .trim();


    const newPin =
        document
            .getElementById("newPin")
            .value
            .trim();


    const account =
        accounts[currentAccountIndex];


    if (oldPin !== account.pin) {

        showModalMessage(
            "Current PIN is incorrect.",
            "error"
        );

        return;
    }


    if (!/^\d{4}$/.test(newPin)) {

        showModalMessage(
            "New PIN must contain exactly 4 numbers.",
            "error"
        );

        return;
    }


    account.pin = newPin;

    saveAccounts();


    showModalMessage(
        "PIN updated successfully.",
        "success"
    );


    setTimeout(
        closeModal,
        900
    );
}


/* =========================================================
   MODAL
========================================================= */

function openModal(title, content) {

    document
        .getElementById("modalTitle")
        .textContent = title;


    document
        .getElementById("modalContent")
        .innerHTML = content;


    document
        .getElementById("modal")
        .classList.remove("hidden");


    document
        .getElementById("modalMessage")
        .className = "message";
}


function closeModal() {

    document
        .getElementById("modal")
        .classList.add("hidden");
}


function showModalMessage(text, type) {

    const message =
        document
            .getElementById("modalMessage");


    message.textContent = text;


    message.className =
        "message " + type;
}


/* =========================================================
   LOGOUT
========================================================= */

function logout() {

    currentAccountIndex = null;


    localStorage.removeItem(
        "myBankCurrentAccount"
    );


    document
        .getElementById("dashboardPage")
        .classList.add("hidden");


    document
        .getElementById("authPage")
        .classList.remove("hidden");


    showLogin();
}


/* =========================================================
   AUTO LOGIN
========================================================= */

if (
    currentAccountIndex !== null &&
    accounts[currentAccountIndex]
) {

    openDashboard();
}