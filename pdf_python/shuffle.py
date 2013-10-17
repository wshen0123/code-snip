#! /usr/bin/env python
import sys, os
from pyPdf import PdfFileWriter, PdfFileReader

in_file_path = raw_input("Enter pdf file name:")
(in_file_dir, in_file_name) = os.path.split(in_file_path)
in_pdf = PdfFileReader(file(in_file_path, "rb"))

out_pdf = PdfFileWriter()

num_page = in_pdf.numPages

if num_page % 2 != 0:
    print "Should pad to even pages"
    sys.exit(0)

for i in range(0, num_page/2):
    out_pdf.addPage(in_pdf.getPage(i))
    out_pdf.addPage(in_pdf.getPage(num_page - i - 1))

out_file_name = os.path.join(in_file_dir, "_" + in_file_name)
outputStream = file(out_file_name, "wb")
out_pdf.write(outputStream)
outputStream.close()
