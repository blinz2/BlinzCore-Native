
class Image {
	private:
		unsigned glImageID, ilImageID;
		int width, height;

	public:
		Image(const char* path);
		
		/**
		 * Loads the image into OpenGL.
		 */
		void load();
};
