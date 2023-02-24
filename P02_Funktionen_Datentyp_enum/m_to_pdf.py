import os
import grip
import pdfkit

os.chdir(r"C:\Users\bazz\Documents\GitHub\snp\praktika\P03_Bounding_Box")
f_md   = r".\README.md"
f_html = r".\REAMDE.html"
f_pdf  = r".\README.pdf"

grip.render_content(f_md)
pdfkit.from_file(f_html, f_pdf)
