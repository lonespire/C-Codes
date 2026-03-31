import zipfile
import xml.etree.ElementTree as ET
import os

def read_docx(file_path):
    try:
        # docx files are zip files
        with zipfile.ZipFile(file_path, 'r') as zip_ref:
            # Read the main document
            xml_content = zip_ref.read('word/document.xml')
            
        # Parse XML
        root = ET.fromstring(xml_content)
        
        # Define namespace
        namespaces = {
            'w': 'http://schemas.openxmlformats.org/wordprocessingml/2006/main'
        }
        
        # Extract text from all paragraphs
        texts = []
        for paragraph in root.findall('.//w:p', namespaces):
            text_nodes = paragraph.findall('.//w:t', namespaces)
            paragraph_text = ''.join([node.text for node in text_nodes if node.text])
            if paragraph_text:
                texts.append(paragraph_text)
        
        return '\n'.join(texts)
    except Exception as e:
        return f"Error: {e}\nFile path: {file_path}"

report_doc = r"d:\code\C++\class\26-3-12\StudentScoreManagement\上机实验报告模板.doc"

print("=" * 80)
print("上机实验报告模板")
print("=" * 80)
content = read_docx(report_doc)
print(content)

# Also check if file exists and its size
if os.path.exists(report_doc):
    print(f"\nFile size: {os.path.getsize(report_doc)} bytes")
