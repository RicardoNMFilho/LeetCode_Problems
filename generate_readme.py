import os
import re

# Diretório atual
root_dir = os.getcwd()

# Regex para pastas no formato LeetCode_123
pattern = re.compile(r"LeetCode_(\d+)$")

# Lista para armazenar problemas resolvidos
solved = []

# Percorre os diretórios
for folder in os.listdir(root_dir):
    if os.path.isdir(folder):
        match = pattern.match(folder)
        if match:
            id_str = match.group(1)
            main_c_path = os.path.join(folder, "main.c")
            if os.path.isfile(main_c_path):
                solved.append((int(id_str), f"{folder}/main.c"))

# Ordena por ID numérico
solved.sort()

# Gera tabela Markdown
table = "| ID    | Resolvido | Caminho               |\n"
table += "|-------|-----------|------------------------|\n"
for id_, path in solved:
    table += f"| {id_:<5} | ✅         | `{path}` |\n"

# Conteúdo do README.md
readme_content = (
    "# 🧠 Meus LeetCodes Resolvidos em C\n\n"
    "Este repositório contém minhas soluções do [LeetCode](https://leetcode.com/) escritas em **C**. "
    "Cada problema está em uma pasta com o padrão `LeetCode_<número>/main.c`.\n\n"
    "## 📌 Progresso\n\n"
    f"{table}\n"
    "> ✅ = Resolvido &nbsp;&nbsp;&nbsp;&nbsp;⬜ = Ainda não resolvido\n\n"
    "## 🧪 Compilação e Execução\n\n"
    "```bash\n"
    "cd LeetCode_<id>\n"
    "gcc main.c -o solution\n"
    "./solution\n"
    "```\n\n"
    "## 🗂️ Estrutura\n\n"
    "```\n"
    "LeetCode_<id>/\n"
    "└── main.c\n"
    "```\n"
)

# Escreve o README.md
try:
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme_content)
    print("✅ README.md gerado com sucesso!")
except Exception as e:
    print(f"❌ Erro ao escrever o README.md: {e}")
