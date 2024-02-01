const ROWS = 10;
const COLS = 10;
const minefield = document.getElementById("minefield");
const tbody = document.createElement("tbody");

// 添加列编号
let colRow = document.createElement("tr");
colRow.innerHTML = "<th class='col-index'></th>";
for (let i = 1; i <= COLS; i++) {
  let colNumber = document.createElement("th");
  colNumber.textContent = i;
  colNumber.classList.add("col-index");
  colRow.appendChild(colNumber);
}
tbody.appendChild(colRow);

// 添加行和行编号
for (let i = 1; i <= ROWS; i++) {
  let row = document.createElement("tr");
  let rowNumber = document.createElement("th");
  rowNumber.textContent = i;
  rowNumber.classList.add("row-index");
  row.appendChild(rowNumber);
  for (let j = 1; j <= COLS; j++) {
    let cell = document.createElement("td");
    cell.dataset.row= i;
    cell.dataset.col= j;
    cell.addEventListener("click", handleCellClick);
    row.appendChild(cell);
  }
  tbody.appendChild(row);
}

function handleCellClick(event) {
    const row = parseInt(event.target.dataset.row);
    const col = parseInt(event.target.dataset.col);
    alert(`Clicked on cell (${row}, ${col})`);
    // 在这里可以添加逻辑来处理点击事件，比如检查是否触发了地雷等等。
}

minefield.appendChild(tbody);