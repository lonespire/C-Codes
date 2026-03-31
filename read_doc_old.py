import textract
import os

def read_old_doc(file_path):
    try:
        text = textract.process(file_path).decode('utf-8')
        return text
    except Exception as e:
        return f"Error: {e}"

report_doc = r"d:\code\C++\class\26-3-12\StudentScoreManagement\上机实验报告模板.doc"

print("=" * 80)
print("上机实验报告模板")
print("=" * 80)
content = read_old_doc(report_doc)
print(content)
