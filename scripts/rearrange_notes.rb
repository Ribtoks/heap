#!/usr/bin/ruby

# script used to sort files managed by Notable into separate directories (as it should be)
# run with
# ruby /path/to/rearrange_notes.rb /path/to/notable/root /path/to/output/root
# remember about assets!

require 'fileutils'

dirpath = ARGV[0]
destpath = ARGV[1]

opts = {}
opts[:encoding] = "UTF-8"

def fix_cotents(filepath)
  text = File.read(filepath)
  out = File.open(filepath, "w")
  skipping_header = 0
  
  text.each_line do |line|
   if line.strip == "---" then
     skipping_header += 1
	 next
   end
  
   if (skipping_header == 1) && (line.strip == "---") then
     out.puts line
     skipping_header += 1
	 next
   end
   
   next if skipping_header == 1   
   
   # fix attachment to be in the same directory of the file in /attachment/ dir
   line.sub! '](@attachment/', '](./attachment/'
   out.puts line
  end
end

Dir.foreach(dirpath, opts) do |filename|
  next if filename == '.' or filename == '..'
  filepath = dirpath + '/' + filename
  contents = File.read(filepath)
  contents.gsub(/tags: \[(.*?)\]/) { |match|
    tag = $1
	destination = destpath + '/' + tag + '/'
	puts "Copying #{filepath} to #{destination}"
	FileUtils.mkdir_p destination
    FileUtils.cp(filepath, destination)
	fix_cotents(destination + '/' + filename)
  }
end
