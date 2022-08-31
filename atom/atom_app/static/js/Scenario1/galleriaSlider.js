


function installGalleriaSlider(data = []) {

	if (!data.length) {
		return
	}

	const galleriaPreviewList = document.querySelector('.centered')
	const galleriaOverlay = document.getElementById('main')

	const galleriaWrapper = document.createElement("div")
	galleriaWrapper.classList.add('galleria__item-list-wrapper')
	galleriaOverlay.append(galleriaWrapper)

	const galleriaList = document.createElement("div")

	galleriaList.classList.add('.galleria__item-list')

	galleriaWrapper.append(galleriaList)

	const closeBtn = document.createElement("button")
	closeBtn.innerText = 'закрыть'
	closeBtn.classList.add('galleria__close')

	document.querySelector('.galleria__item-list-wrapper').append(closeBtn)

	data.forEach((item, index) => {
		let galleriaItem = document.createElement("div")
		galleriaItem.classList.add('galleria__item');
		galleriaItem.setAttribute('galleria', index)

		if (item.type === 'img') {
			galleriaItem.innerHTML = `<img src="${item.src}"  loading='eager' class='galleria__item-img' alt="">`
		}

		if (item.type === 'video') {
			galleriaItem.innerHTML = `
				<video class="galleria__item-video" width="100%" poster="${item.poster}" pointer-events="none"> <source src="${item.src}" /> </video>`
		}

		galleriaList.append(galleriaItem)

		let previewItem = document.createElement("img")

		previewItem.classList.add('galleria__preview-item');
		previewItem.setAttribute('data-galleria', index)

		previewItem.src = item.poster

		galleriaPreviewList.append(previewItem)
	});


	function setActiveItem(event) {
		if (!event.target.classList.contains('galleria__preview-item')) {
			return
		}

		removeActiveItem()

		const currentIndex = event.target.dataset.galleria
		galleriaOverlay.classList.add('active')
		galleriaList.classList.add('active')
		galleriaWrapper.classList.add('active')
		galleriaList.children[currentIndex].classList.add('active')
		galleriaPreviewList.children[currentIndex].classList.add('active')

		const videoTag = galleriaList.children[currentIndex].querySelector('video')
		if (videoTag) {
			setTimeout(() => {
				videoTag.play()
			}, 1000);
		}
	}

	function removeActiveItem() {

		Array.from(galleriaList.children).forEach((item, index) => {
			const videoTag = item.querySelector('video')
			if (videoTag) {
				videoTag.load()
			}
			item.classList.remove('active')
		})
		Array.from(galleriaPreviewList.children).forEach((item, index) => {
			item.classList.remove('active')
		})

	}

	function closeModal() {
		galleriaWrapper.classList.remove('active')
		galleriaOverlay.classList.remove('active');
		galleriaList.classList.remove('active')
		removeActiveItem()
	}

	galleriaOverlay.addEventListener('click', (event) => {
		if (event.target === galleriaOverlay) {
			closeModal()
		}
	})

	galleriaPreviewList.addEventListener('click', setActiveItem)
	galleriaList.addEventListener('click', setActiveItem)
	closeBtn.addEventListener('click', closeModal)


}

