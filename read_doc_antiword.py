import subprocess
import os

def read_old_doc_with_antiword(file_path):
    try:
        # Try using antiword if available
        result = subprocess.run(['antiword', file_path], capture_output=True, text=True, encoding='gbk')
        if result.returncode == 0:
            return result.stdout
        else:
            return f"antiword error: {result.stderr}"
    except FileNotFoundError:
        return "antiword not installed. Trying alternative method..."
    except Exception as e:
        return f"Error: {e}"

report_doc = r"d:\code\C++\class\26-3-12\StudentScoreManagement\上机实验报告模板.doc"

print("=" * 80)
print("上机实验报告模板")
print("=" * 80)
content = read_old_doc_with_antiword(report_doc)
print(content)

# Also try using olefile and pywin32
try:
    import win32com.client
    print("\n\n" + "=" * 80)
    print("Using COM to read DOC file")
    print("=" * 80)
    word = win32com.client.Dispatch("Word.Application")
    word.Visible = False
    doc = word.Documents.Open(report_doc)
    text = doc.Content.Text
    print(text)
    doc.Close()
    word.Quit()
except Exception as e:
    print(f"\nCOM method error: {e}")
