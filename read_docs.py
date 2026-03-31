from docx import Document
import sys

def read_docx(file_path):
    try:
        doc = Document(file_path)
        text = []
        for para in doc.paragraphs:
            text.append(para.text)
        return '\n'.join(text)
    except Exception as e:
        return f"Error reading {file_path}: {e}"

task_doc = r"d:\code\C++\class\26-3-12\数据结构课程第一次上机任务说明.docx"
report_doc = r"d:\code\C++\class\26-3-12\StudentScoreManagement\上机实验报告模板.doc"

print("=" * 80)
print("数据结构课程第一次上机任务说明")
print("=" * 80)
print(read_docx(task_doc))
print("\n")

print("=" * 80)
print("上机实验报告模板")
print("=" * 80)
print(read_docx(report_doc))
