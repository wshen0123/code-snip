#! /usr/bin/env python
import sys, os
from pyPdf import PdfFileWriter, PdfFileReader

file_path = "/home/wshen1/Desktop/"
in_pdf_1 = PdfFileReader(file(file_path + "1.pdf", "rb"))
in_pdf_2 = PdfFileReader(file(file_path + "2.pdf", "rb"))

out_pdf = PdfFileWriter()

num_page = in_pdf_1.numPages

for i in range(0, num_page):
    out_pdf.addPage(in_pdf_1.getPage(i))
    out_pdf.addPage(in_pdf_2.getPage(i))

outputStream = file(file_path + "0.pdf", "wb")
out_pdf.write(outputStream)
outputStream.close()
